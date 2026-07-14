
const menuButton = document.querySelector('.menu-button');
const navLinks = document.querySelector('.nav-links');

menuButton.addEventListener('click', () => {
  const open = navLinks.classList.toggle('open');
  menuButton.setAttribute('aria-expanded', String(open));
});

document.querySelectorAll('.nav-links a').forEach(link => {
  link.addEventListener('click', () => {
    navLinks.classList.remove('open');
    menuButton.setAttribute('aria-expanded', 'false');
  });
});

const filters = document.querySelectorAll('.filter');
const cards = document.querySelectorAll('.product-card');

filters.forEach(button => {
  button.addEventListener('click', () => {
    filters.forEach(item => item.classList.remove('active'));
    button.classList.add('active');

    const filter = button.dataset.filter;
    cards.forEach(card => {
      const show = filter === 'todos' || card.dataset.category === filter;
      card.classList.toggle('hidden', !show);
    });
  });
});

const whatsappNumber = '5519974029689';

function openWhatsApp(message) {
  const url = `https://wa.me/${whatsappNumber}?text=${encodeURIComponent(message)}`;
  window.open(url, '_blank', 'noopener,noreferrer');
}

document.querySelectorAll('.reserve-button').forEach(button => {
  button.addEventListener('click', () => {
    openWhatsApp(`Olá! Tenho interesse na peça: ${button.dataset.product}. Ela ainda está disponível?`);
  });
});

document.querySelectorAll('.whatsapp-link').forEach(link => {
  link.addEventListener('click', event => {
    event.preventDefault();
    openWhatsApp(link.dataset.message);
  });
});

document.querySelector('#year').textContent = new Date().getFullYear();
