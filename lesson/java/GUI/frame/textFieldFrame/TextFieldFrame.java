package frame.textFieldFrame;

import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class TextFieldFrame extends JFrame {
    private JTextField tField1;
    private JTextField tField2;
    private JTextField tField3;
    private JPasswordField pField;

    public TextFieldFrame () {
        super("Testing JTextField and JPasswordField");
        setLayout(new FlowLayout());
        
        // construct textfield with 10 columns
        tField1 = new JTextField(10);
        // add TextField component to the JFrame           
        add(tField1);
        
        // construct textfield with default text
        tField2 = new JTextField("Enter text here");
        add(tField2);

        // construct textfield with default text and 21 columns
        tField3 = new JTextField("Uneditable text field", 21);
        tField3.setEditable(false); // disable editing
        add(tField3);

        // construct passwordfield with default text
        pField = new JPasswordField("Hidden text");
        add(pField);

        // register event handlers
        TextFieldHandler handler = new TextFieldHandler();
        tField1.addActionListener(handler);
        tField2.addActionListener(handler);
        tField3.addActionListener(handler);
        pField.addActionListener(handler);
    }

    private class TextFieldHandler implements ActionListener {
        // abstract method ActionListener.actionPerformed(ActionEvent) must implement
        public void actionPerformed (ActionEvent event) {
            String message = ""; // declare string to display

            // getSource returns the object on which the Event initially occurred

            // user pressed Enter in JTextField textField1            
            if (event.getSource() == tField1)
                message = "tField1: ";
            else if (event.getSource() == tField2) 
                message = "tField2: ";
            else if (event.getSource() == tField3) 
                message = "tField3: ";
            else
                message = "pField: ";
                
            message += event.getActionCommand();

            // JOptionPane.showMessageDialog(parentComponent, message, title, messageType);
            JOptionPane.showMessageDialog(null, message);    
        }
    }
}