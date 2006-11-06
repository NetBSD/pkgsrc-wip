# $NetBSD: Makefile,v 1.1.1.1 2006/11/06 20:42:33 uhabel Exp $

DISTNAME=	RRDTool-OO-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSCHILLI/}
MAINTAINER=	uli@habel.name
HOMEPAGE=	http://search.cpan.org/dist/RRDTool-OO/
COMMENT=	RRDTool::OO implementation for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

#PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=		auto/RRDTool/OO/.packlist
#MAKE_PARAMS+=		< /dev/null

DEPENDS+= p5-Log-Log4perl>=1.01:../../wip/p5-Log-Log4perl

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
