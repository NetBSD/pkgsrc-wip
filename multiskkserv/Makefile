# $NetBSD: Makefile,v 1.6 2010/09/11 08:46:15 obache Exp $
#

DISTNAME=	multiskkserv-20100128-ac
PKGNAME=	${DISTNAME:S/-ac//}
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://github.com/sina-ht/multiskkserv/
COMMENT=	Simple skk multi-dictionary server
LICENSE=	gnu-gpl-v2

DEPENDS=	skk-jisyo-cdb-[0-9]*:../../inputmethod/skk-jisyo-cdb

PKG_DESTDIR_SUPPORT=	user-destdir

FIND_PREFIX:=		SKKJISYOCDBDIR=skk-jisyo-cdb

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	${DOCSDIR}

INSTALL_DOCS=		README \
			README.j

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

RCD_SCRIPTS=	multiskkserv

FILES_SUBST=	SKKJISYOCDBDIR=${SKKJISYOCDBDIR}

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor

.include "../../mk/find-prefix.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
