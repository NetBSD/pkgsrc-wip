# $NetBSD: Makefile,v 1.1.1.1 2006/04/10 14:02:52 lkundrak Exp $

DISTNAME=	Text-CHM-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	lkundrak@skosi.org
COMMENT=	Module that implements a support for handling CHM files

PERL5_PACKLIST=		auto/Text/CHM/.packlist

.include "../../devel/chmlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
