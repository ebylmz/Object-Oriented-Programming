package interfaces.Shape2D;

public class Triangle {
    private double _e1, _e2, _e3;

    public void setEdge (double edge1, double edge2, double edge3) {
        if (checkDegenerate(edge1, edge2, edge3)) {
            _e1 = edge1;
            _e2 = edge2;
            _e3 = edge3;
        }
    }

    public void edge (double edge1, double edge2, double edge3) {
            edge1 = _e1;
            edge2 = _e2;
            edge3 = _e3;
    }

    // checks if given edges can produce an non degenerate triangle
    // returns true for non degenerate triangle
    private boolean checkDegenerate (double edge1, double edge2, double edge3) {
        return  (Math.max(edge3, edge2) - Math.min(edge3, edge2) < edge1) && (edge1 < edge3 + edge2) &&
                (Math.max(edge3, edge1) - Math.min(edge3, edge1) < edge2) && (edge2 < edge3 + edge1) &&
                (Math.max(edge1, edge2) - Math.min(edge1, edge2) < edge3) && (edge3 < edge1 + edge2);
    }    

    public double area () {
        double s = (_e1 + _e2 + _e3) / 2.0; // semi perimeter
        return Math.sqrt(s * (s - _e1) * (s - _e2) * (s - _e3));
    }

    public double circumference () {return _e1 + _e2 + _e3;}
}