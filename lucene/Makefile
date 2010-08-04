# $NetBSD: Makefile,v 1.1.1.1 2010/08/04 00:07:25 jihbed Exp $
#

DISTNAME=	lucene-3.0.2
CATEGORIES=	textproc java
MASTER_SITES=	http://apache.cyberuse.com/lucene/java/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://lucene.apache.org/
COMMENT=	Full-text search engine for Java
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
USE_JAVA2=  yes

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15


INSTALLATION_DIRS=	lib/java/lucene		\
						lib/java/lucene/lib		\
						lib/java/lucene/contrib 	\
						share/doc/lucene

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${DESTDIR}${PREFIX}/lib/java/lucene
	${INSTALL_DATA} ${WRKSRC}/*.war ${DESTDIR}${PREFIX}/lib/java/lucene
	cd ${WRKSRC}/lib && pax -rw -pp . ${DESTDIR}${PREFIX}/lib/java/lucene/lib
	cd ${WRKSRC}/contrib && pax -rw -pp . ${DESTDIR}${PREFIX}/lib/java/lucene/contrib
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/lib/java/lucene
	cd ${WRKSRC}/docs && pax -rw -pm * ${DESTDIR}${PREFIX}/share/doc/lucene

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
