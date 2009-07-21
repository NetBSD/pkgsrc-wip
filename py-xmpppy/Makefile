# $NetBSD: Makefile,v 1.9 2009/07/21 19:11:46 jihbed Exp $
#

DISTNAME=	xmpppy-0.5.0rc1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rc1//}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmpppy/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://xmpppy.sourceforge.net/
COMMENT=	XMPP (Jabber) library for Python
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=		yes

DOCDIR=		${PREFIX}/share/doc/py-xmpppy

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.css \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
