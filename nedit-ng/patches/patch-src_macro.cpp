$NetBSD$

* fix signedness warnings that are due to changes in latests gsl::span

--- src/macro.cpp.orig	2020-02-05 05:36:17.000000000 +0000
+++ src/macro.cpp
@@ -181,7 +181,7 @@ std::string MacroErrorCategory::message(
 boost::optional<TextArea::EventFlags> flagsFromArguments(Arguments arguments, int firstFlag) {
 
 	TextArea::EventFlags f = TextArea::NoneFlag;
-	for (int i = firstFlag; i < arguments.size(); ++i) {
+	for (std::size_t i = firstFlag; i < arguments.size(); ++i) {
 
 		const std::string s = to_string(arguments[i]);
 
@@ -471,7 +471,7 @@ std::error_code readSearchArgs(Arguments
 ** looking for keywords
 */
 Direction searchDirection(Arguments arguments, int index) {
-	for (int i = index; i < arguments.size(); ++i) {
+	for (std::size_t i = index; i < arguments.size(); ++i) {
 		QString arg;
 		if (std::error_code ec = readArgument(arguments[i], &arg)) {
 			return Direction::Forward;
@@ -494,7 +494,7 @@ Direction searchDirection(Arguments argu
 ** looking for keywords
 */
 bool searchKeepDialogs(Arguments arguments, int index) {
-	for (int i = index; i < arguments.size(); ++i) {
+	for (std::size_t i = index; i < arguments.size(); ++i) {
 		QString arg;
 		if (std::error_code ec = readArgument(arguments[i], &arg)) {
 			return Preferences::GetPrefKeepSearchDlogs();
@@ -517,7 +517,7 @@ bool searchKeepDialogs(Arguments argumen
 ** looking for keywords
 */
 WrapMode searchWrap(Arguments arguments, int index) {
-	for (int i = index; i < arguments.size(); ++i) {
+	for (std::size_t i = index; i < arguments.size(); ++i) {
 		QString arg;
 		if (std::error_code ec = readArgument(arguments[i], &arg)) {
 			return Preferences::GetPrefSearchWraps();
@@ -541,7 +541,7 @@ WrapMode searchWrap(Arguments arguments,
 */
 SearchType searchType(Arguments arguments, int index) {
 
-	for (int i = index; i < arguments.size(); ++i) {
+	for (std::size_t i = index; i < arguments.size(); ++i) {
 		QString arg;
 
 		if (std::error_code ec = readArgument(arguments[i], &arg)) {
@@ -1457,7 +1457,7 @@ std::error_code findIncrMS(DocumentWidge
 	auto win = MainWindow::fromDocument(document);
 	Q_ASSERT(win);
 
-	int i;
+	std::size_t i;
 	bool continued = false;
 
 	QString arg;
@@ -2247,7 +2247,7 @@ std::error_code replaceInStringMS(Docume
 	int64_t copyStart;
 	int64_t copyEnd;
 	bool force = false;
-	int i;
+	std::size_t i;
 
 	// Validate arguments and convert to proper types
 	if (arguments.size() < 3 || arguments.size() > 5) {
@@ -2389,7 +2389,7 @@ std::error_code tPrintMS(DocumentWidget 
 		return MacroErrorCode::TooFewArguments;
 	}
 
-	for (int i = 0; i < arguments.size(); i++) {
+	for (std::size_t i = 0; i < arguments.size(); i++) {
 		if (std::error_code ec = readArgument(arguments[i], &string)) {
 			return ec;
 		}
@@ -2470,7 +2470,7 @@ std::error_code dialogMS(DocumentWidget 
 	}
 
 	// check that all button labels can be read
-	for (int i = 1; i < arguments.size(); i++) {
+	for (std::size_t i = 1; i < arguments.size(); i++) {
 		if (std::error_code ec = readArgument(arguments[i], &btnLabel)) {
 			return ec;
 		}
@@ -2488,7 +2488,7 @@ std::error_code dialogMS(DocumentWidget 
 	if (arguments.size() == 1) {
 		prompt->addButton(QDialogButtonBox::Ok);
 	} else {
-		for (int i = 1; i < arguments.size(); ++i) {
+		for (std::size_t i = 1; i < arguments.size(); ++i) {
 			if (std::error_code ec = readArgument(arguments[i], &btnLabel)) {
 				// NOTE(eteran): does not report
 			}
@@ -2512,7 +2512,7 @@ std::error_code stringDialogMS(DocumentW
 
 	QString btnLabel;
 	QString message;
-	long i;
+	unsigned long i;
 
 	/* Ignore the focused window passed as the function argument and put
 	   the dialog up over the window which is executing the macro */
@@ -2554,7 +2554,7 @@ std::error_code stringDialogMS(DocumentW
 	if (arguments.size() == 1) {
 		prompt->addButton(QDialogButtonBox::Ok);
 	} else {
-		for (int i = 1; i < arguments.size(); ++i) {
+		for (std::size_t i = 1; i < arguments.size(); ++i) {
 			if (std::error_code ec = readArgument(arguments[i], &btnLabel)) {
 				// NOTE(eteran): does not report
 			}
@@ -2607,7 +2607,7 @@ std::error_code calltipMS(DocumentWidget
 	std::string txtArg;
 	bool anchored = false;
 	bool lookup   = true;
-	int i;
+	std::size_t i;
 	int anchorPos;
 	auto mode      = Tags::SearchMode::None;
 	auto hAlign    = TipHAlignMode::Left;
@@ -2894,7 +2894,7 @@ std::error_code listDialogMS(DocumentWid
 	QString btnLabel;
 	QString message;
 	QString text;
-	long i;
+	unsigned long i;
 
 	/* Ignore the focused window passed as the function argument and put
 	   the dialog up over the window which is executing the macro */
@@ -2946,7 +2946,7 @@ std::error_code listDialogMS(DocumentWid
 	if (arguments.size() == 2) {
 		prompt->addButton(QDialogButtonBox::Ok);
 	} else {
-		for (int i = 2; i < arguments.size(); ++i) {
+		for (std::size_t i = 2; i < arguments.size(); ++i) {
 			if (std::error_code ec = readArgument(arguments[i], &btnLabel)) {
 				// NOTE(eteran): does not report
 			}
@@ -2977,7 +2977,7 @@ std::error_code stringCompareMS(Document
 	QString rightStr;
 	QString argStr;
 	bool considerCase = true;
-	int i;
+	std::size_t i;
 	int compareResult;
 
 	if (arguments.size() < 2) {
