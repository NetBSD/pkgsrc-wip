# $NetBSD$

DISTNAME=	pipe-viewer-0.0.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=trizen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trizen/pipe-viewer/
COMMENT=	Lightweight application for searching and playing videos from YouTube
LICENSE=	artistic-2.0

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/WWW/PipeViewer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
