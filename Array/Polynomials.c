#include <stdio.h>

#define MAX 10

struct term {
	int coeff;
	int exp;
};

struct poly {
	struct term t[10];
	int nofTerms;
};

void initpoly(struct poly *);
void polyappend(struct poly *, int c, int e);
struct poly polyadd(struct poly, struct poly);
void display(struct poly);
struct poly polymul(struct poly p1, struct poly p2);

int main() {
	struct poly p1, p2, p3, p4;
	
	initpoly(&p1);

	polyappend(&p1, 1, 7);
	polyappend(&p1, 2, 6);
	polyappend(&p1, 3, 5);
	polyappend(&p1, 4, 4);
	polyappend(&p1, 5, 2);

	display(p1);

	initpoly(&p2);

        polyappend(&p2, 1, 7);
        polyappend(&p2, 2, 6);
        polyappend(&p2, 3, 5);
        polyappend(&p2, 4, 4);
        polyappend(&p2, 5, 2);

	display(p2);

	p3 = polyadd(p1, p2);

	display(p3);

	p4 = polymul(p1, p2);
	display(p4);

	return 0;
}

void initpoly(struct poly *p) {
	int i;
	p->nofTerms = 0;

	for (i = 0; i < MAX; i++) {
		p->t[i].coeff = 0;
		p->t[i].exp = 0;
	}
}

void polyappend(struct poly *p, int c, int e) {
	p->t[p->nofTerms].coeff = c;
	p->t[p->nofTerms].exp = e;

	(p->nofTerms)++;
}


void display(struct poly p) {
	int flag = 0, i;

	for (i = 0; i < p.nofTerms; i++) {
		if (p.t[i].exp != 0)
			printf("%dx^%d + ", p.t[i].coeff, p.t[i].exp);
		else {
			printf("%d", p.t[i].coeff);
			flag = 1;
		}
	}

	if (!flag)
		printf("\b\b");
	printf("\n");
}

struct poly polyadd(struct poly p1, struct poly p2) {
	int i, j, c;
	struct poly p3;
	initpoly(&p3);

	if (p1.nofTerms > p2.nofTerms)
		c = p1.nofTerms;
	else
		c = p2.nofTerms;

	for (i = 0, j = 0; i <= c; p3.nofTerms++) {

		if (p1.t[i].coeff == 0 && p2.t[j].coeff == 0)
			break;

		if (p1.t[i].exp == p2.t[j].exp) {
			p3.t[p3.nofTerms].coeff = p1.t[i].coeff + p2.t[j].coeff;
			p3.t[p3.nofTerms].exp = p1.t[i].exp;
			i++;
			j++;
		} else if (p1.t[i].exp > p2.t[j].exp) {
			p3.t[p3.nofTerms].coeff = p1.t[i].coeff;
			p3.t[p3.nofTerms].exp = p3.t[i].exp;
			i++;
		} else {
			p3.t[p3.nofTerms].coeff = p2.t[j].coeff;
                        p3.t[p3.nofTerms].exp = p2.t[j].exp;
                        j++;
		}
	}
	return p3;
}

struct poly polymul(struct poly p1, struct poly p2) {
	int coeff, exp;
	struct poly temp, p3;

	initpoly(&p3);
	initpoly(&temp);

	if (p1.nofTerms != 0 && p2.nofTerms != 0) {
		int i;
		for (i = 0; i < p1.nofTerms; i++) {
			int j;
			struct poly p;
			initpoly(&p);

			for (j = 0; j < p2.nofTerms; j++) {
				coeff = p1.t[i].coeff * p2.t[j].coeff;
				exp = p1.t[i].exp + p2.t[j].exp;
				polyappend(&p, coeff, exp);
			}
			if (i != 0) {
				p3 = polyadd(temp, p);
				temp = p3;
			} else temp = p;
		}
	}
	return p3;
}
