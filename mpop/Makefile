# $NetBSD: Makefile,v 1.1.1.1 2005/11/12 16:52:04 leonardschmidt Exp $
#

DISTNAME=	mpop-0.8.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpop/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://mpop.sourceforge.net/
COMMENT=	Small, fast and portable POP3 client

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

PKG_SYSCONFSUBDIR=	mpop

EGDIR=		${PREFIX}/share/examples/mpop
CONF_FILES=	${EGDIR}/mpoprc.example ${PKG_SYSCONFDIR}/sample.mpoprc

INFO_FILES=	mpop.info

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
