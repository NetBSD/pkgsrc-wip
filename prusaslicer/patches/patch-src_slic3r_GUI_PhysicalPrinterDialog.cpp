$NetBSD$

Fix ambiguous overload errors with wxWidgets 3.2.4
http://github.com/prusa3d/PrusaSlicer/issues/11768

--- src/slic3r/GUI/PhysicalPrinterDialog.cpp.orig	2024-01-07 03:26:15.232175668 +0000
+++ src/slic3r/GUI/PhysicalPrinterDialog.cpp
@@ -467,7 +467,7 @@ void PhysicalPrinterDialog::build_printh
     // Always fill in the "printhost_port" combo box from the config and select it.
     {
         Choice* choice = dynamic_cast<Choice*>(m_optgroup->get_field("printhost_port"));
-        choice->set_values({ m_config->opt_string("printhost_port") });
+        choice->set_values(std::vector<std::string>({ m_config->opt_string("printhost_port") }));
         choice->set_selection();
     }
 
