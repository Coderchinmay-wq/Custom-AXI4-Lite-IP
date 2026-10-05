extern "C" int compute(int A, int B);

int main()
{
    if (compute(3,4) != 25)
        return 1;

    if (compute(5,12) != 169)
        return 1;

    if (compute(10,20) != 500)
        return 1;

    return 0;
}