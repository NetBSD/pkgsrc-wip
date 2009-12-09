# $NetBSD: Makefile,v 1.6 2009/12/09 22:42:11 gschwarz Exp $

DISTNAME=	tftp-hpa-5.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.kernel.org/pub/software/network/tftp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/tftp-hpa/
COMMENT=	Enhanced version of the BSD TFTP client and server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	autoconf gmake
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_search_getopt_long=no
.endif

MAKE_ENV+=	INSTALLROOT="${DESTDIR}"

.include 	"options.mk"

INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
