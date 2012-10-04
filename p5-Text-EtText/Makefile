# $NetBSD: Makefile,v 1.2 2012/10/04 19:12:00 asau Exp $
#

DISTNAME=	Text-EtText-2.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://ettext.taint.org/devel/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://ettext.taint.org/devel/
COMMENT=	Simple plain-text format which allows conversion to and from HTML

PKG_DESTDIR_SUPPORT=	none

PERL5_PACKLIST=	auto/Text/EtText/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
