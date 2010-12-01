import sys
sys.path.append("../../../")

from hermes2d.modules.electrostatics import Electrostatics
from hermes2d.hermes2d import Linearizer
from hermes2d.plot import sln2png

def main():
    e = Electrostatics()
    e.set_mesh_str("\na = 1.0  # size of the mesh\nb = sqrt(2)/2\n\nvertices =\n{\n  { 0, -a },    # vertex 0\n  { a, -a },    # vertex 1\n  { -a, 0 },    # vertex 2\n  { 0, 0 },     # vertex 3\n  { a, 0 },     # vertex 4\n  { -a, a },    # vertex 5\n  { 0, a },     # vertex 6\n  { a*b, a*b }  # vertex 7\n}\n\nelements =\n{\n  { 0, 1, 4, 3, 0 },  # quad 0\n  { 3, 4, 7, 0 },     # tri 1\n  { 3, 7, 6, 0 },     # tri 2\n  { 2, 3, 6, 5, 0 }   # quad 3\n}\n\nboundaries =\n{\n  { 0, 1, 1 },\n  { 1, 4, 2 },\n  { 3, 0, 4 },\n  { 4, 7, 2 },\n  { 7, 6, 2 },\n  { 2, 3, 4 },\n  { 6, 5, 2 },\n  { 5, 2, 3 }\n}\n\ncurves =\n{\n  { 4, 7, 45 },  # +45 degree circular arcs\n  { 7, 6, 45 }\n}\n");
    e.set_initial_mesh_refinement(2)
    e.set_initial_poly_degree(4)
    e.set_material_markers([0])
    e.set_permittivity_array([1])
    e.set_charge_density_array([1])
    e.set_boundary_markers_value([4])
    e.set_boundary_values([0])
    e.set_boundary_markers_derivative([1, 2, 3])
    e.set_boundary_derivatives([0, 0, 0])
    r, sln = e.calculate()
    assert r is True
    print "Saving solution to 'solution.png'"
    sln2png(sln, "solution.png")

if __name__ == "__main__":
    main()
