CARGO_GIT_FILES+=	comemo 9b520e8f5284d1c39d0bb13eb426f923972775f8 https://github.com/typst/comemo comemo-0.1.0
CARGO_GIT_FILES+=	pixglyph e3ff0272d6723cdada91a00b0c99cda0e5adb56d https://github.com/typst/pixglyph pixglyph-0.1.0
CARGO_GIT_FILES+=	unicode-math-class a7ac7dd75cd79ab2e0bdb629036cb913371608d2 https://github.com/typst/unicode-math-class unicode-math-class-0.1.0
#CARGO_GIT_FILES+=	biblatex 932ad283dd45dd88d4fa14dc5b9bda7a270ba027 https://github.com/typst/biblatex biblatex
#CARGO_GIT_FILES+=	hayagriva 754efb7e1034bcd4d4f1366e432197edbbfb9ed5 https://github.com/typst/hayagriva hayagriva
#CARGO_GIT_FILES+=	iai 3f0f92736408ebce6545808b98e0cb2aea89b7dd https://github.com/reknih/iai iai

DISTFILES?=			${DEFAULT_DISTFILES}
.for name rev url path in ${CARGO_GIT_FILES}
CARGO_GIT_DISTFILE:=		${name}-${rev}.tar.gz
CARGO_GIT_DISTFILES:=		${CARGO_GIT_DISTFILES} ${CARGO_GIT_DISTFILE}
SITES.${CARGO_GIT_DISTFILE}=	-${url}/archive/${rev}.tar.gz
.endfor
DISTFILES:=			${DISTFILES} ${CARGO_GIT_DISTFILES}
