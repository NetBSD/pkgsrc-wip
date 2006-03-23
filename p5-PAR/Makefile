# $NetBSD: Makefile,v 1.1.1.1 2006/03/23 19:21:22 kuli0020 Exp $

DISTNAME=	PAR-0.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AU/AUTRIJUS/}

MAINTAINER=	kuli0020@umn.edu
COMMENT=	Perl Archive Toolkit

DEPENDS+=	p5-Archive-Zip>=1.00:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Compress-Zlib>=1.16:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Module-ScanDeps>=0.45:../../devel/p5-Module-ScanDeps
DEPENDS+=	p5-Module-Signature>=0.35:../../security/p5-Module-Signature
DEPENDS+=	p5-PAR-Dist>=0.06:../../devel/p5-PAR-Dist
DEPENDS+=	p5-B-Deobfuscate>=0.00:../../wip/p5-B-Deobfuscate
DEPENDS+=	{perl>=5.8.0,p5-File-Temp>=0.05}:../../devel/p5-File-Temp

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/PAR/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
