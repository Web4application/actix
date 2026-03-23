
	•	Home page (index.html)
	•	Documents page (docs.html) with PDF/Markdown preview
	•	Embed page (embed.html) with https://qubuhub.org/ iframe
	•	CSS (paper.css + toc.css) for beautiful, readable, responsive layout
	•	JS (theme.js + toc.js) for dark/light toggle and smooth scroll TOC
	•	Folder structure ready for GitHub Pages, Netlify, Vercel, or a server

⸻

📁 Full Folder Structure

paperweb/
├── index.html
├── docs.html
├── embed.html
├── assets/
│   ├── css/
│   │   ├── paper.css
│   │   └── toc.css
│   ├── js/
│   │   ├── theme.js
│   │   └── toc.js
│   └── images/
│       └── logo.webp  (optional)
└── docs/
    ├── intro.pdf
    ├── manual.docx
    └── readme.md


⸻

🌟 1. CSS — assets/css/paper.css

:root {
  --bg: #fdfdfd;
  --text: #111;
  --accent: #0077cc;
  --code-bg: #f5f5f5;
  --border: #ddd;
  --radius: 6px;
  font-size: 18px;
}

@media (prefers-color-scheme: dark) {
  :root {
    --bg: #121212;
    --text: #fafafa;
    --accent: #66aaff;
    --code-bg: #1e1e1e;
    --border: #333;
  }
}

body {
  margin: 0 auto;
  max-width: 900px;
  font-family: system-ui, -apple-system, "Inter", sans-serif;
  line-height: 1.6;
  padding: 40px;
  background: var(--bg);
  color: var(--text);
  transition: background 0.3s, color 0.3s;
}

nav {
  display: flex;
  gap: 20px;
  margin-bottom: 2rem;
  border-bottom: 1px solid var(--border);
  padding-bottom: 10px;
}

nav a {
  font-weight: 600;
  color: var(--accent);
  text-decoration: none;
}

nav a:hover {
  text-decoration: underline;
}

h1, h2, h3 {
  font-weight: 700;
  margin-top: 2rem;
}

pre {
  background: var(--code-bg);
  padding: 16px;
  border-radius: var(--radius);
  overflow-x: auto;
}

iframe {
  width: 100%;
  height: 500px;
  border: 1px solid var(--border);
  border-radius: var(--radius);
  box-shadow: 0 5px 15px rgba(0,0,0,0.05);
}

button#theme-btn {
  position: fixed;
  top: 20px;
  right: 20px;
  padding: 6px 12px;
  background: var(--accent);
  color: #fff;
  border: none;
  border-radius: var(--radius);
  cursor: pointer;
}


⸻

assets/css/toc.css

#toc {
position: sticky;
  top: 20px;
  border-left: 4px solid var(--accent);
  padding-left: 10px;
  margin-bottom: 2rem;
}

#toc ul {
  list-style: none;
  padding-left: 0;
}

#toc a {
  text-decoration: none;
  color: var(--accent);
  display: block;
  margin: 5px 0;
}

#toc a:hover {
  text-decoration: underline;
}


⸻

💻 3. JS — assets/js/theme.js

const toggleTheme = () => {
  const currentBg = getComputedStyle(document.documentElement).getPropertyValue('--bg').trim();
  if (currentBg === '#fdfdfd') {
    document.documentElement.style.setProperty('--bg', '#121212');
    document.documentElement.style.setProperty('--text', '#fafafa');
  } else {
    document.documentElement.style.setProperty('--bg', '#fdfdfd');
    document.documentElement.style.setProperty('--text', '#111');
  }
};

document.addEventListener('DOMContentLoaded', () => {
  const btn = document.createElement('button');
  btn.id = 'theme-btn';
  btn.textContent = 'Toggle Theme';
  btn.onclick = toggleTheme;
  document.body.appendChild(btn);
});


⸻

🖱️ 4. JS — assets/js/toc.js

document.querySelectorAll('#toc a').forEach(link => {
  link.addEventListener('click', e => {
    e.preventDefault();
    document.querySelector(link.getAttribute('href')).scrollIntoView({
      behavior: 'smooth'
    });
  });
});


⸻

🏠 5. Home — index.html

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Paperweb Home</title>
  <link rel="stylesheet" href="assets/css/paper.css">
  <script src="assets/js/theme.js" defer></script>
</head>
<body>

<nav>
  <a href="index.html">Home</a>
  <a href="docs.html">Documents</a>
  <a href="embed.html">qubuhub.org</a>
</nav>

<h1>Welcome to Paperweb</h1>
<p>This is a clean, paper-style website integrating external content (like <a href="https://example.org/">qubuhub.org</a>) into a modern, readable layout.</p>

</body>
</html>


⸻

📄 6. Documents — docs.html

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Paperweb Documents</title>
  <link rel="stylesheet" href="assets/css/paper.css">
  <link rel="stylesheet" href="assets/css/toc.css">
  <script src="assets/js/theme.js" defer></script>
  <script src="assets/js/toc.js" defer></script>
  <script src="https://cdn.jsdelivr.net/npm/marked/marked.min.js"></script>
</head>
<body>

<nav>
  <a href="index.html">Home</a>
  <a href="docs.html">Documents</a>
  <a href="embed.html"> qubuhub.org</a>
</nav>

<h1>Document Library</h1>

<aside id="toc">
  <h2>Contents</h2>
  <ul>
    <li><a href="#section1">PDF Preview</a></li>
    <li><a href="#section2">Markdown Preview</a></li>
  </ul>
</aside>

<h2 id="section1">PDF Preview</h2>
<object data="docs/intro.pdf" type="application/pdf" width="100%" height="600">
  <p>PDF preview not supported — <a href="docs/intro.pdf" target="_blank">download here</a>.</p>
</object>

<h2 id="section2">Markdown Preview</h2>
<div id="md-content"></div>
<script>
fetch('docs/readme.md')
  .then(res => res.text())
  .then(md => { document.getElementById('md-content').innerHTML = marked.parse(md); });
</script>

</body>
</html>


⸻

🖼️ 7. Embed — embed.html

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>qubuhub.org Embedded</title>
  <link rel="stylesheet" href="assets/css/pper.css">
  <script src="assets/js/theme.js" defer></script>
</head>
<body>

<nav>
  <a href="index.html">Home</a>
  <a href="docs.html">Documents</a>
  <a href="embed.html">qubuhub.org</a>
</nav>

<h1> qubuhub.org. in Paperweb</h1>
<p>This iframe embeds <strong>https://qubuhub.org..org/</strong> into a clean, paperweb-style layout.</p>

<iframe
  src="https://qubuhub.org..org/"
  sandbox
  title="qubuhub.org. Embedded"
></iframe>

</body>
</html>

