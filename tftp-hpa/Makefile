# $NetBSD: Makefile,v 1.8 2012/10/07 17:17:33 asau Exp $

DISTNAME=	tftp-hpa-5.2
CATEGORIES=	net
MASTER_SITES=	http://www.kernel.org/pub/software/network/tftp/tftp-hpa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/tftp-hpa/
COMMENT=	Enhanced version of the BSD TFTP client and server
LICENSE=	original-bsd

GNU_CONFIGURE=	YES
USE_TOOLS+=	autoconf gmake
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_search_getopt_long=no
.endif

MAKE_ENV+=	INSTALLROOT="${DESTDIR}"

.include 	"options.mk"

.if !empty(PKG_OPTIONS:Minet6)
# the following is needed at least on MacOS 10.11
# and should not hurt on earlier versions
CFLAGS.Darwin+=	-D__APPLE_USE_RFC_3542
.endif

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
