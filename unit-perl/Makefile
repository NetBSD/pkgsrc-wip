# $NetBSD$

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Perl module for NGINX Unit

LANG=		perl
MODNAME=	${LANG}

MAINTAINER=	osa@FreeBSD.org

USE_TOOLS+=	perl

post-configure:
	cd ${WRKSRC} && \
	./configure ${LANG} --module=${MODNAME}

.include "../../lang/perl5/buildlink3.mk"
.include "../../wip/unit/ext.mk"
.include "../../wip/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
