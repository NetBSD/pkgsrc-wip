# $NetBSD$

DISTNAME=	opendylan-2014.1
CATEGORIES=	lang
GIT_REPOSITORIES=	opendylan
GIT_REPO.opendylan=	git://github.com/dylan-lang/opendylan.git
GIT_BRANCH.opendylan=	dev/netbsd-port

USE_TOOLS+=	autoconf automake autoreconf perl gmake

WRKSRC=		${WRKDIR}/opendylan

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylan-lang/opendylan/
COMMENT=	Multi-paradigm functional and OO programming language
#LICENSE=	# TODO: (see mk/license.mk)
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../wip/mk/git-package.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
