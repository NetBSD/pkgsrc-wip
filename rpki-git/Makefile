# $NetBSD: Makefile,v 1.5 2014/09/10 09:12:46 thomasklausner Exp $

DISTNAME=	rpki-0.0
CATEGORIES=	net security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://rpki.net/
COMMENT=	RPKI package collection
LICENSE=	original-bsd

GIT_REPOSITORIES=	rpki
GIT_REPO.rpki=		git@github.com:dragonresearch/rpki.net.git

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_TOOLS+=	perl python

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
#CONFIGURE_ARGS+=	--disable-django
#CONFIGURE_ARGS+=	--disable-system-openssl

WRKSRC=			${WRKDIR}/rpki

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
