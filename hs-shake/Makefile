# $NetBSD: Makefile,v 1.3 2014/02/18 14:29:41 szptvlfn Exp $

DISTNAME=	shake-0.11.1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@a-net.email.ne.jp
COMMENT=	Build system library, like Make, but more accurate dependencies
LICENSE=	modified-bsd

INSTALLATION_DIRS=	share/examples/${DISTNAME}

post-install:
	for example in \
		${WRKSRC}/Examples/C/constants.c \
		${WRKSRC}/Examples/C/constants.h \
		${WRKSRC}/Examples/C/main.c      \
		${WRKSRC}/Examples/MakeTutor/Makefile \
		${WRKSRC}/Examples/MakeTutor/hellofunc.c \
		${WRKSRC}/Examples/MakeTutor/hellomake.c \
		${WRKSRC}/Examples/MakeTutor/hellomake.h \
		${WRKSRC}/Examples/Tar/list.txt          \
		${WRKSRC}/Examples/Ninja/*.ninja ; do \
		${INSTALL_DATA} "$${example}" ${DESTDIR}${PREFIX}/share/examples/${DISTNAME}; done

.include "../../wip/mk/haskell.mk"
.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
