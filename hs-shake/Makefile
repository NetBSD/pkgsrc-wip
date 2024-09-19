# $NetBSD: Makefile,v 1.11 2014/05/27 21:38:23 szptvlfn Exp $

DISTNAME=	shake-0.11.4
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Build system library, like Make, but more accurate dependencies
LICENSE=	modified-bsd

INSTALLATION_DIRS=	share/examples/${DISTNAME}
INSTALLATION_DIRS+=	share/examples/${DISTNAME}/Examples
INSTALLATION_DIRS+=	share/examples/${DISTNAME}/Examples/C
INSTALLATION_DIRS+=	share/examples/${DISTNAME}/Examples/MakeTutor
INSTALLATION_DIRS+=	share/examples/${DISTNAME}/Examples/Tar
INSTALLATION_DIRS+=	share/examples/${DISTNAME}/Examples/Ninja

post-install:
	for a in \
		${WRKSRC}/Examples/C/constants.c \
		${WRKSRC}/Examples/C/constants.h \
		${WRKSRC}/Examples/C/main.c; do \
		${INSTALL_DATA} "$${a}" ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}/Examples/C; done
	for b in \
		${WRKSRC}/Examples/MakeTutor/Makefile \
		${WRKSRC}/Examples/MakeTutor/hellofunc.c \
		${WRKSRC}/Examples/MakeTutor/hellomake.c \
		${WRKSRC}/Examples/MakeTutor/hellomake.h; do \
		${INSTALL_DATA} "$${b}" ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}/Examples/MakeTutor; done
	${INSTALL_DATA} ${WRKSRC}/Examples/Tar/list.txt \
		${DESTDIR}${PREFIX}/share/examples/${DISTNAME}/Examples/Tar
	for g in \
		${WRKSRC}/Examples/Ninja/*.ninja; do \
		${INSTALL_DATA} "$${g}" ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}/Examples/Ninja; done

.include "../../wip/mk/haskell.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
