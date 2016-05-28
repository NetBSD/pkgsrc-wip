# $NetBSD: Makefile,v 1.7 2012/11/13 20:26:27 othyro Exp $

DISTNAME=		boinc
PKGNAME=		boinc-lib-1
PKGREVISION=		2
CATEGORIES=		net

COMMENT=		Libraries for the BOINC distributed computing application


GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake m4 pkg-config gmake
USE_LANGUAGES=		c c++

#LIBTOOL_OVERRIDE=	m4/libtool.m4
SHLIBTOOL_OVERRIDE=	m4/libtool.m4

CONFIGURE_ARGS+=	--disable-server	\
			--disable-client

.include "../../wip/boinc-lib/Makefile.common"

CVS_REPOSITORIES=	boinc

pre-configure:
	cd ${WRKSRC} &&			\
	aclocal -I m4 && autoheader &&	\
	automake && autoconf

.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
