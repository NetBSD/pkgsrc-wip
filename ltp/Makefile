# $NetBSD: Makefile,v 1.1 2014/12/14 16:26:32 krytarowski Exp $

DISTNAME=		ltp-git
CATEGORIES=		wip
GIT_REPOSITORIES=	ltp
GIT_REPO.ltp=		git@github.com:linux-test-project/ltp.git
WRKSRC=			${WRKDIR}/ltp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux-test-project.github.io/
COMMENT=	Testing Linux, one syscall at a time
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	lib/ltp.pc.in

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
