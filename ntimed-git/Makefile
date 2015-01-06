# $NetBSD: Makefile,v 1.1 2015/01/06 16:59:59 thomasklausner Exp $

DISTNAME=		ntimed-0.0
CATEGORIES=		time net
MASTER_SITES=		https://github.com/bsdphk/Ntimed

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/bsdphk/Ntimed
COMMENT=		Network Time Synchronization

GIT_REPOSITORIES=	Ntimed
GIT_REPO.Ntimed= 	git://github.com/bsdphk/Ntimed.git

WRKSRC=			${WRKDIR}/Ntimed
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
