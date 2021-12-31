package interfaces.Shape2D;

public class Rectangle implements Shape2D {
    private double _width;
    private double _height;
    
    public void setWidth (double width) {
        if (width >= 0)
            _width = width;
    }

    public void setHeight (double height) {
        if (height >= 0)
            _height = height;
    }

    public double width () {return _width;}

    public double height () {return _height;}

    public double area () {return _width * _height;}

    public double circumference () {return 2 * (_width + _height);}
}
