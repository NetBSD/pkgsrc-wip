# $NetBSD: Makefile,v 1.172 2017/08/30 21:00:46 kamil Exp $

DISTNAME=	dosemu2-2.0
CATEGORIES=	emulators

GIT_REPOSITORIES=	dosemu2
GIT_REPO.dosemu2=	https://github.com/stsp/dosemu2.git

WRKSRC=		${WRKDIR}/dosemu2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qemu-project.org/
COMMENT=	Run DOS programs under UNIX
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoconf automake autoreconf gmake
HAS_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh


.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
