# $NetBSD$

DISTNAME=	libgabe
CATEGORIES=	security devel
PKGNAME=	libgabe-0.0.0
MASTER_SITES=	${MASTER_SIZE_GITHUB:=schanzen/}
GITHUB_PROJECT=	libgabe
EXTRACT_SUFX=	# none

GIT_REPOSITORIES=	libgabe
GIT_REPO.libgabe=	https://github.com/schanzen/libgabe.git
GIT_REVISION=		f72c594eaed35d5a506e8f6c091200a73e17e702

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://github.com/schanzen/
COMMENT=	Ciphertext-Policy Attribute-Based Encryption library, fork of libbswabe
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libpbc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
