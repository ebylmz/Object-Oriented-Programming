import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class Frame extends JFrame {
    public Frame () {
        super("JFrame tittle goes here"); // setTitle("....");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 420);
        setResizable(false);
        setVisible(true);

        ImageIcon img = new ImageIcon("logo1.png");
        setIconImage(img.getImage());
        getContentPane().setBackground(new Color(0xFF665A));
    }
}
