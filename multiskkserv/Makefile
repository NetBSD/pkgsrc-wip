# $NetBSD: Makefile,v 1.1.1.1 2010/08/18 10:23:12 ryo-on Exp $
#

DISTNAME=	multiskkserv-20100128
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://ryo-on.users.sourceforge.net/distrib/
COMMENT=	Simple skk multi-dictionary server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR}

INSTALL_DOCS=		README \
			README.j

USE_LIBTOOL=	yes
USE_TOOLS+=	automake
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	multiskkserv

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
