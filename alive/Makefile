# $NetBSD $
#

DISTNAME=	alive-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://savannah.gnu.org/download/alive/

MAINTAINER=	oht@users.sourceforge.net
HOMEPAGE=	http://www.gnu.org/software/alive/
COMMENT=	Login software for Swedish Telia ADSL/Comhem cable Internet users

AUTOMAKE_REQD=  1.7.1
MANCOMPRESSED=	yes
GNU_CONFIGURE=  yes

LIBS.SunOS=	-lnsl -lsocket

pre-configure:
	cd ${WRKSRC};                                           \
	${ACLOCAL};                                             \
	${AUTOHEADER};                                          \
	${AUTOMAKE} -a --foreign -i;                            \
	${AUTOCONF}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
