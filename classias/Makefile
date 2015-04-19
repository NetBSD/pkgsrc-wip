# $NetBSD: Makefile,v 1.1 2015/04/19 16:55:50 cheusov Exp $

DISTNAME=	0.0.0
PKGNAME=	classias-${DISTNAME}
CATEGORIES=	math
#MASTER_SITES=	https://github.com/chokkan/classias/archive/
DIST_SUBDIR=	classias

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.chokkan.org/software/classias/
COMMENT=	Collection of machine-learning algorithms for classification
LICENSE=	modified-bsd

GIT_REPOSITORIES=	classias
GIT_REPO.classias=	git://github.com/chokkan/classias.git
.include "../../wip/mk/git-package.mk"

WRKSRC=		${WRKDIR}/classias
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

USE_TOOLS+=	autoconf autoreconf automake

CONFIGURE_ARGS+=	--with-liblbfgs=${PREFIX}

.include "../../mk/bsd.prefs.mk"

pre-configure:
	set -e; cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../math/liblbfgs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
