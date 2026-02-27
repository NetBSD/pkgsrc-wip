$NetBSD$

--- drivers/pwm/sunxi_pwm.c.orig	2018-11-14 16:10:06.000000000 +0000
+++ drivers/pwm/sunxi_pwm.c
@@ -170,6 +170,7 @@ static const struct pwm_ops sunxi_pwm_op
 static const struct udevice_id sunxi_pwm_ids[] = {
 	{ .compatible = "allwinner,sun5i-a13-pwm" },
 	{ .compatible = "allwinner,sun50i-a64-pwm" },
+	{ .compatible = "allwinner,sun7i-a20-pwm" },
 	{ }
 };
 
