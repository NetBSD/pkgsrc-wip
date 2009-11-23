# $NetBSD: Makefile,v 1.2 2009/11/23 09:05:12 jihbed Exp $
#

DISTNAME=	spade-2.0rc3
PKGNAME=	spade-2.0
CATEGORIES=	devel python
MASTER_SITES=	http://spade.gti-ia.dsic.upv.es/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://spade.gti-ia.dsic.upv.es/index.html
COMMENT=	SPADE is an agent platform based on the XMPP/Jabber technology
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-psyco>=1.6:../../lang/py-psyco
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-gmpy>=1.04:../../wip/py-gmpy
DEPENDS+=	jython>=2.5.1:../../wip/jython


PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/spade

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/etc/spade/spade.xml,${PREFIX}/etc/spade/spade.xml,g'
SUBST_SED.paths+=	-e 's,/etc/spade/xmppd.xml,${PREFIX}/etc/spade/xmppd.xml,g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,spade/mtp,${PREFIX}/${PYSITELIB}/spade/mtp,g'
SUBST_SED.paths+=	-e 's,etc/spade.xml,${PREFIX}/etc/spade.xml,g'
SUBST_SED.paths+=	-e 's,/usr/bin/runspade.py,${PREFIX}/bin/runspade.py,g'
SUBST_FILES.paths+=	runspade.py spade.sh configure.py
SUBST_MESSAGE.paths=	Fixing header search paths.


post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
