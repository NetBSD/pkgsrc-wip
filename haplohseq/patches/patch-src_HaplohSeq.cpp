$NetBSD$

--- src/HaplohSeq.cpp.orig	2021-01-23 22:44:43.000000000 +0000
+++ src/HaplohSeq.cpp
@@ -195,14 +195,14 @@ void HaplohSeq::runBafHaplohseq(	std::st
 	for (unsigned int i = 0; i < numParamEventStarts; i++) {
 
 		// Create thread pool
-		boost::asio::io_service ioService;
-	//	boost::asio::io_service::work work(ioService);
-		boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(ioService));
+		boost::asio::io_context ioContext;
+	//	boost::asio::io_context::work work(ioContext);
+		boost::shared_ptr<boost::asio::io_context::work> work(new boost::asio::io_context::work(ioContext));
 		boost::thread_group threadPool;
 
 		// Spawn worker threads
 		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_context::*)())&boost::asio::io_context::run, &ioContext));
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
@@ -220,7 +220,7 @@ void HaplohSeq::runBafHaplohseq(	std::st
 
 			std::cout << "Posting job to thread pool for chromosome " << chr << "\n";
 			// IMPORTANT: do not pass shared_ptr by reference because the shared_ptr expects a new pointer to the object
-			ioService.post(boost::bind(&HaplohSeq::runBafHaplohseqChr, this,
+			ioContext.post(boost::bind(&HaplohSeq::runBafHaplohseqChr, this,
 													chr,
 													boost::ref(chrHmms),
 													boost::ref(fp),
@@ -413,14 +413,14 @@ void HaplohSeq::runVcfHaplohseq(	std::st
 	for (unsigned int i = 0; i < numParamEventStarts; i++) {
 
 		// Create thread pool
-		boost::asio::io_service ioService;
-	//	boost::asio::io_service::work work(ioService);
-		boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(ioService));
+		boost::asio::io_context ioContext;
+	//	boost::asio::io_context::work work(ioContext);
+		boost::shared_ptr<boost::asio::io_context::work> work(new boost::asio::io_context::work(ioContext));
 		boost::thread_group threadPool;
 
 		// Spawn worker threads
 		for (std::size_t t = 0; t < numThreads; t++) {
-			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_service::*)())&boost::asio::io_service::run, &ioService));
+			threadPool.create_thread(boost::bind((boost::asio::io_context::count_type (boost::asio::io_context::*)())&boost::asio::io_context::run, &ioContext));
 		}
 
 		std::map<std::string, boost::shared_ptr<Hmm> > chrHmms;
@@ -438,7 +438,8 @@ void HaplohSeq::runVcfHaplohseq(	std::st
 
 //			std::cout << "Posting job to thread pool for chromosome " << chr << "\n";
 			// IMPORTANT: do not pass shared_ptr by reference because the shared_ptr expects a new pointer to the object
-			ioService.post(boost::bind(&HaplohSeq::runVcfHaplohseqChr, this,
+			// https://github.com/boostorg/asio/issues/110
+			ioContext.get_executor().post(boost::bind(&HaplohSeq::runVcfHaplohseqChr, this,
 													chr,
 													boost::ref(chrHmms),
 													boost::ref(fp),
