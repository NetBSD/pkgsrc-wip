# $NetBSD$

DISTNAME=	swinehub-1.501
CATEGORIES=	www
MASTER_SITES=	http://nishi.e3t.cc/pub/dist/swinehub/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	http://sw.e3t.cc/sw/~e3team/swinehub
COMMENT=	Subversion frontend
LICENSE=	modified-bsd

DEPENDS+=	subversion>=0:../../devel/subversion
DEPENDS+=	ap24-subversion>=0:../../www/ap2-subversion
DEPENDS+=	apache>=0:../../www/apache24

USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

post-configure:
	cd ${WRKSRC} && cp GNUmakefile Makefile

post-build:
	mkdir -p ${DESTDIR}/usr/pkg/var/swinehub/htdocs
	touch ${DESTDIR}/usr/pkg/var/swinehub/auth
	printf "[groups]\n#%%NEW-TEAM\n" > ${DESTDIR}/usr/pkg/var/swinehub/authz
	cp ${WRKSRC}/bin/swinehub.cgi ${DESTDIR}/usr/pkg/var/swinehub/
	cp ${WRKSRC}/dist/* ${DESTDIR}/usr/pkg/var/swinehub/htdocs/
	mv ${DESTDIR}/usr/pkg/var/swinehub/htdocs/swinehub.png ${DESTDIR}/usr/pkg/var/swinehub/htdocs/icon.png

.include "../../mk/bsd.pkg.mk"
