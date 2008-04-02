# $NetBSD: Makefile,v 1.1.1.1 2008/04/02 18:32:28 rhialto Exp $

DISTNAME=	logjam-4.5.3
CATEGORIES=	misc
MASTER_SITES=	http://logjam.danga.com/download/
#MASTER_SITES=	http://neugierig.org/software/logjam/download/

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://logjam.danga.com/
#HOMEPAGE=	http://neugierig.org/software/logjam
COMMENT=	GTK2 interface to livejournals, eg www.livejournal.com

GNU_CONFIGURE=	yes
USE_TOOLS += gmake
USE_X11=	yes

.include "options.mk"

.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
