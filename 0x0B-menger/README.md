This project implements is intended to implement the Sierpinski Carpet:

	Start with a solid (filled) square C(0). Divide this into 9 smaller congruent squares. Remove the interior of the center square (that is, do not remove the boundary) to get C(1). Now subdivide each of the eight remaining solid squares into 9 congruent squares and remove the center square from each to obtain C(2). Continue to repeat the construction to obtain a decreasing sequence of sets

	C(0)⊃C(1)⊃C(2)⊃C(3)⊃⋯

	The Sierpinski carpet is the intersection of all the sets in this sequence, that is, the set of points that remain after this construction is repeated infinitely often. The figures below show the first four iterations. The squares in red denote some of the smaller congruent squares used in the construction. 