# $NetBSD: Makefile,v 1.3 2015/01/10 20:19:03 thomasklausner Exp $

DISTNAME=		ltp-0.0
CATEGORIES=		devel
GIT_REPOSITORIES=	ltp
GIT_REPO.ltp=		https://github.com/linux-test-project/ltp.git
WRKSRC=			${WRKDIR}/ltp

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux-test-project.github.io/
COMMENT=	Testing Linux, one syscall at a time
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake aclocal autoconf automake autoreconf perl unzip zip

PKGCONFIG_OVERRIDE+=	lib/ltp.pc.in
REPLACE_PYTHON+=	execltp.in
REPLACE_PERL+=		./testcases/kernel/containers/netns/netns_container_ftp.pl

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

INSTALL_MAKE_FLAGS+=	SKIP_IDCHECK=1

.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
