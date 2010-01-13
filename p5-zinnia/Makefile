# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:13:36 obache Exp $
#

.include "../../wip/zinnia/Makefile.common"

PKGNAME=	p5-${DISTNAME}

COMMENT=	Zinnia perl module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/zinnia/.packlist

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../wip/zinnia/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
