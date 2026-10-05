extern "C" {

int compute(int A, int B)
{
#pragma HLS INTERFACE s_axilite port=A bundle=CTRL
#pragma HLS INTERFACE s_axilite port=B bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    return (A * A) + (B * B);
}

}