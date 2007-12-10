# $NetBSD: Makefile,v 1.3 2007/12/10 00:32:40 uhabel Exp $

DISTNAME=	RRDTool-OO-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSCHILLI/}
MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RRDTool-OO/
COMMENT=	RRDTool::OO implementation for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/RRDTool/OO/.packlist

DEPENDS+= p5-Log-Log4perl>=1.01:../../wip/p5-Log-Log4perl

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
