#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

int main()
{
    Point A, B, C, D;
    float ABAC, ABAD, CDCA, CDCB;
    int ACD = 0, BCD = 0, CAB = 0, DAB = 0;

    scanf("%f %f %f %f\n %f %f %f %f", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);

    ABAC = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    ABAD = (B.x - A.x) * (D.y - A.y) - (D.x - A.x) * (B.y - A.y);
    CDCA = (D.x - C.x) * (A.y - C.y) - (A.x - C.x) * (D.y - C.y);
    CDCB = (D.x - C.x) * (B.y - C.y) - (B.x - C.x) * (D.y - C.y);

    //printf("ABAC:%f ABAD:%f CDCA:%f CDCB:%f\n", ABAC, ABAD, CDCA, CDCB);

    if ((ABAC * ABAD < 0) && (CDCA * CDCB < 0))
    {
        printf("YES");
        return 0;
    }

    if (ABAC == 0)
    {
        if (((A.x - C.x) * (B.x - C.x) + (A.y - C.y) * (B.y - C.y)) <= 0)
            CAB = 1;
    }

    if (ABAD == 0)
    {
        if (((A.x - D.x) * (B.x - D.x) + (A.y - D.y) * (B.y - D.y)) <= 0)
            DAB = 1;
    }

    if (CDCA == 0)
    {
        if (((C.x - A.x) * (D.x - A.x) + (C.y - A.y) * (D.y - A.y)) <= 0)
            ACD = 1;
    }

    if (CDCB == 0)
    {
        if (((C.x - B.x) * (D.x - B.x) + (C.y - B.y) * (D.y - B.y)) <= 0)
            BCD = 1;
    }

    //printf("CAB:%d DAB:%d ACD:%d BCD:%d\n", CAB, DAB, ACD, BCD);

    if (CAB + DAB + ACD + BCD)
        printf("YES");
    else
        printf("NO");

    return 0;
}
