# $NetBSD: Makefile,v 1.6 2006/02/18 03:51:11 poppnk Exp $
#

DISTNAME=		jamvm-1.4.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/
USE_TOOLS+=	gmake

DEPENDS+=	classpath-0.19:../../lang/classpath
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.	if ${MACHINE_ARCH} == "i386"
MACHINE_GNU_PLATFORM=i686-pc-linux-gnu
.	endif
.endif


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jamvm ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/jni.h ${PREFIX}/include/
	${INSTALL_DATA_DIR} ${PREFIX}/share/jamvm/classes/
	unzip -o ${WRKSRC}/lib/classes.zip -d ${PREFIX}/share/jamvm/classes/


#.include "../../lang/classpath/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
