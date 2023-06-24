# $NetBSD: Makefile,v 1.38 2016/10/25 17:57:39 kamil Exp $

DISTNAME=	fossil-src-1.37
PKGNAME=	${DISTNAME:S/-src/1/}
CATEGORIES=	devel scm
MASTER_SITES=	https://fossil-scm.org/home/tarball/version-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fossil-scm.org/
COMMENT=	High-reliability, distributed software configuration management (v1)
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/fossil1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin/fossil1
	${INSTALL_MAN} ${WRKSRC}/fossil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/fossil1.1
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-BSD2.txt \
		${DESTDIR}${PREFIX}/share/doc/fossil1
	${INSTALL_DATA} ${WRKSRC}/src/linenoise.h \
		${DESTDIR}${PREFIX}/share/doc/fossil1

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
