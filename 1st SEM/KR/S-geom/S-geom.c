#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Rect {
    struct Point lt;
    struct Point rb;
};

struct Rect transform (struct Rect r)
{
	struct Rect tmp = r;
	
	r.lt.x = - tmp.rb.x;
	r.lt.y = - tmp.rb.y;
	r.rb.x = - tmp.lt.x;
	r.rb.y = - tmp.lt.y;
	
	return r;
}

int main()
{
    struct Rect rect, a = {{2, 4}, {7, 1}};
    rect = transform(a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    return 0;
}
