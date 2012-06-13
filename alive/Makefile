# $NetBSD: Makefile,v 1.6 2012/06/13 06:00:22 othyro Exp $
#

DISTNAME=	alive-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://savannah.gnu.org/download/alive/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://www.gnu.org/software/alive/
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

AUTOMAKE_REQD=	1.7.1
MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake

LIBS.SunOS+=	-lnsl -lsocket

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && automake -a --foreign -i
	cd ${WRKSRC} && autoconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
