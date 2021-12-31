package interfaces.Shape2D;

public class Square extends Rectangle {
    public void setWidth (double width) {
        super.setWidth(width);
        super.setHeight(width);
    }

    public void setHeight (double heigth) {
        super.setWidth(heigth);
        super.setHeight(heigth);
    }
}