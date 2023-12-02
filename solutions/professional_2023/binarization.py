import torch

# Аппроксимация функции бинаризации входов
class ParabolaSignApproximator(torch.autograd.Function):
    @staticmethod
    def forward(ctx, input):
        ctx.save_for_backward(input)
        return input.sign()

    @staticmethod
    def backward(ctx, grad_output):
        input, = ctx.saved_tensors
        grad_input = grad_output.clone()
        grad_input[input < -1] = 0
        grad_input[input > 1] = 0
        grad_input[(input >= -1) & (input < 0)] *= 2 * input[(input >= -1) & (input < 0)] + 2
        grad_input[(input >= 0) & (input < 1)] *= -2 * input[(input >= 0) & (input < 1)] + 2
        return grad_input

# Аппроксимация функции бинаризации весов
class STESignApproximator(torch.autograd.Function):
    @staticmethod
    def forward(ctx, input):
        return input.sign()

    @staticmethod
    def backward(ctx, grad_output):
        # Производная функции Sign равна 0 везде, кроме 0, 
        # но STE использует производную равную 1 для обучения
        return grad_output

# Прямой проход сигнала через полносвязный слой с бинаризованными весами и входами
def forward(x, weights):
    xb = ParabolaSignApproximator.apply(x)
    wb = STESignApproximator.apply(weights)
    return torch.nn.functional.linear(xb, wb).sum()


n = int(input())
m = int(input())

x = torch.tensor([
            [float(k) for k in input().split()] for _ in range(n)
        ], requires_grad=True)

n_2 = int(input())
m_2 = int(input())

weights = torch.tensor([
            [float(k) for k in input().split()] for _ in range(n_2)
        ], requires_grad=True)

# Функция потерь и обратное распространение
loss = forward(x, weights)
loss.backward()

# Вывод градиентов по входным значениям и весам

x_grad = x.grad.tolist()
weights_grad = weights.grad.tolist()


for x_row in x_grad:
    print(*x_row)

for w_row in weights_grad:
    print(*w_row)