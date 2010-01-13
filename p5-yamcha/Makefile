# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 10:46:10 obache Exp $
#

.include "../../wip/yamcha/Makefile.common"

PKGNAME=	p5-${DISTNAME}

COMMENT=	YamCha perl module

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

CONFIGURE_DIRS=	perl

PERL5_PACKLIST=		auto/YamCha/.packlist

BUILDLINK_API_DEPENDS.yamcha+=	yamcha>=${PKGVERSION_NOREV}
.include "../../wip/yamcha/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
