# $NetBSD: Makefile,v 1.3 2006/10/29 08:32:55 shattered Exp $
#

DISTNAME=		rdup-0.2.14
CATEGORIES=		sysutils
MASTER_SITES=		http://miek.nl/projects/rdup/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://miek.nl/projects/rdup/
COMMENT=		Backup utility listing changed files only

DEPENDS+=		bash>=3.0:../../shells/bash

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${LOCALBASE}/bin/bash
REPLACE_FILES.bash=     \
	sh-restore/monthday.sh.in \
	sh-restore/rorrim.sh.in \
	sh-tools/crypt.sh.in \
	sh-tools/gzip.sh.in \
	sh-tools/hist.sh.in \
	sh-tools/mirror.sh.in \
	sh-tools/yesterday.sh.in \
	sh-wrapper/dump-here.sh.in \
	sh-wrapper/dump.sh.in \
	sh-wrapper/restore.sh.in

REPLACE_PERL+=		pl-tools/gzip.pl.in pl-tools/mirror.pl.in

post-install:
	${RMDIR} ${PREFIX}/etc/rdup

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
