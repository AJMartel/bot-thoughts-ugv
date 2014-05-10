/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.botthoughts.gcs;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.net.URL;
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JLayeredPane;

/**
 *
 * @author Michael Shimniok
 */
public final class GaugePanel extends JLayeredPane {
    private int myWidth;
    private int myHeight;
    private Image image;
    private ArrayList<GaugeNeedle> needle;
    private int currentLayer;
    
    /** Instantiates a new GaugePanel
     * 
     */
    public GaugePanel() {
        initComponents();
        currentLayer = 0;
        needle = new ArrayList<>();
    }

    public void addNeedle(GaugeNeedle n) {
        needle.add(n); // add needle to list of needles
        n.setSize(this.getSize());
//        System.out.print("currentLayer=");
//        System.out.println(currentLayer);
        this.add(n, new Integer(++currentLayer)); // add needle (JPanel) to JLayeredPane
        this.setVisible(true);
    }
    

    /**
     * This returns a count of needles on the gauge.
     * @return (int) count of needles
     */
    public int getNeedleCount() {
        return this.needle.size();
    }
    
    
    /** loads the specified image as an Image
     * 
     * @param filename is the name of the image file
     * @return Image loaded from the filename
     */
    private Image loadImage(String filename) {
        Image myImage = null;
        
        if (filename != null) {
            try {              
                URL url = getClass().getResource(filename);
                if (url != null) {
                    myImage = new ImageIcon(url).getImage();
                    myWidth = this.getWidth();
                    myHeight = this.getHeight();
                }
            } catch (Exception ex) {
                // handle exception...
                System.out.println("Error loading image: " + ex.getMessage().toString());
            }
        }
        return myImage;
    }
    
    
    
    /**
     * Creates new form GaugePanel
     */
    public void setImage(String filename) {
        image = loadImage(filename);
    }

    
    /**
     * 
     * @param g 
     */
    @Override
    public void paintComponent(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        
        super.paintComponent(g);
        if (image != null) {
            g2d.drawImage(image, 0, 0, myWidth, myHeight, null);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );
    }// </editor-fold>//GEN-END:initComponents
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables

}
