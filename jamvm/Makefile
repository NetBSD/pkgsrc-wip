# $NetBSD: Makefile,v 1.5 2005/11/27 00:27:54 poppnk Exp $
#

DISTNAME=		jamvm-1.4.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/

DEPENDS+=	classpath-0.19:../../lang/classpath
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jamvm ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/jni.h ${PREFIX}/include/
	${INSTALL_DATA_DIR} ${PREFIX}/share/jamvm/classes/
	unzip -o ${WRKSRC}/lib/classes.zip -d ${PREFIX}/share/jamvm/classes/

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
